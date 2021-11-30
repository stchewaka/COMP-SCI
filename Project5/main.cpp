//Simon Chewaka
//11/20/21
//11/21/21
//Program 5

#include <iostream>
#include <fstream>
#include <string>
#include "Audio.h"
#include "Video.h"

int main() {
    
    std::ifstream in;
    std::ofstream outAudio;                    
    std::ofstream outVideo;                       
    std::string file1 = "Program5Data.txt";       
    std::string file2 = "audio.txt";           
    std::string file3 = "video.txt";           

    Media* mediaFiles[200] = { nullptr };

    
    int readIndex = 0;           
    int writeIndex = 0;           
    char fileType = ' ';

   
    in.open(file1);
    if (!in.is_open()) {
        std::cout << "Failed to open file: " << file1 << std::endl;
        return -1;
    }
    else {
        
        outAudio.open(file2);           // audio.txt
        outVideo.open(file3);           // video.txt
        if (!outAudio.is_open() || !outVideo.is_open()) {
            std::cout << "Failed to open either " << file2 << " or " << file3 << std::endl;
            return -1;
        }
        else {
            while (in >> fileType) {
                in.ignore();
                
                switch (fileType) {
                case 'A':
                    mediaFiles[readIndex] = new Audio;
                    break;
                case 'V':
                    mediaFiles[readIndex] = new Video;
                    break;
                }
                mediaFiles[readIndex]->ReadData(in);
                readIndex++;
            }
        }

      
        while (mediaFiles[writeIndex] != nullptr
            && writeIndex <= readIndex) {
            if (mediaFiles[writeIndex]->getType() == "Audio") {
                mediaFiles[writeIndex]->WriteData(outAudio);
            }
            else {
                mediaFiles[writeIndex]->WriteData(outVideo);
            }
            writeIndex++;
        }
    }
    in.close();
    outAudio.close();
    outVideo.close();



    return 0;
}