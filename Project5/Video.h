#ifndef VIDEO_H
#define VIDEO_H

#include "Media.h"

class Video : public Media {
protected:
    std::string resolution;
    std::string formatDescriptor;
    std::string qualitySpec;
    std::string type;

public:
    Video();
    Video(std::string uniqueID, std::string name, int runningTime,
        std::string resolution, std::string formatDescriptor, std::string qualitySpec);
    ~Video();
    bool ReadData(std::istream& in);
    bool WriteData(std::ostream& out);
    std::string getType() const;
};

#endif // !VIDEO_H
