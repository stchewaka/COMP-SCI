#ifndef AUDIO_H
#define AUDIO_H

#include "Media.h"

class Audio : public Media {
private:
	std::string formatDescriptor;
	std::string qualitySpec;
	std::string type;

public:
	Audio();
	Audio(std::string uniqueID, std::string name, int runningTime, std::string formatDescriptor, std::string qualitySpec);
	~Audio();
	bool ReadData(std::istream& in);
	bool WriteData(std::ostream& out);
	std::string getType() const;
};
#endif // !AUDIO_H
