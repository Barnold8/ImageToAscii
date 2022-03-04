#include <stdint.h>
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
 
 
#define STB_IMAGE_IMPLEMENTATION
#include "Externlib/stb-master/stb-master/stb_image.h"
 
class pixel{
public:
    int R,G,B;
 
    pixel(){};
 
    pixel(int R_, int G_, int B_){
 
        R = R_;
        G = G_;
        B = B_;
 
    }
 
    void readDat(){
 
        std::cout << "R " << R << " G " << G << " B " << B << std::endl;
    }
    int brightness(){return R + G + B;}
};
 
std::vector<pixel> PixelArr(uint8_t* data, const int w, const int h){
 
    std::vector<pixel> P;
    int R,G,B;
    pixel P_D;
 
    for(int i = 0; i < w*h*3; i+= 3){
 
        R = (int)data[i];
        G = (int)data[i+1];
        B = (int)data[i+2];
        P_D = pixel(R,G,B);
        P.push_back(P_D);
    }
 
    return P;
 
}
 
std::string pixelToAscii(pixel data){
 
    std::string asciiStr = "$@B%8&WM#*oahkbdpqwmZO0QLCJUYXzcvunxrjft/\\|()1{}[]?-_+~<>i!lI;:,\"^`'. ";
    // std::string asciiStr = " .:-=+*#%@";
    std::string c = " ";
    int position = ((int) data.brightness() / asciiStr.length());
    c[0] = asciiStr[position];
    return c;
 
}


int checks(int argc, char** argv){

    int arglength, hasExtension;
    arglength = hasExtension = 0;
    std::string path;

    if(argc != 2){
        std::cout << "Error: need a file path for the image...\n";
    }

    path = argv[1];
    for(int i = 0; i < path.length(); i++){

        if(path[i] == '.'){
            hasExtension = 1;
            if(!(path[i+1] == 'p' && path[i+2] == 'n' && path[i+3] == 'g')){
                std::cout << "Error: file extension wasnt png...\n";
                return 1;
            }
        }

    }
    if(hasExtension != 1){

        std::cout << "Error: file has no file extension, cant decipher if its a png or not...\n";

        return 1;

    }    

    return 0;
}

int main(int argc, char** argv) {

    if(checks(argc,argv)!= 0){return -1;}

    int width, height, bpp, length,pixelMount;
    std::string s = "";
 
    uint8_t* rgb_image = stbi_load(argv[1], &width, &height, &bpp, 3);
    length = width*height;
 
    std::vector<pixel> P = PixelArr(rgb_image,width,height);
 
    for(int i = 0; i < P.size(); i++){
        if(i % width == 0){
            s.append("\n");
            s.append(pixelToAscii(P[i]));
        }
        else{
            s.append(pixelToAscii(P[i]));
        }
    }
 
 
 
    std::ofstream out("ImageAscii.txt");
    out << s;
    out.close();
    stbi_image_free(rgb_image);
 
    return 0;
}