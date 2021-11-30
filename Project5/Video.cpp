#include "Video.h"

Video::Video() : Media() {
	resolution = "";
	formatDescriptor = "";
	qualitySpec = "";
	type = "Video";
}


Video::Video(std::string uniqueID, std::string name, int runningTime,
	std::string resolution, std::string formatDescriptor, std::string qualitySpec)
	: Media(uniqueID, name, runningTime) {
	this->resolution = resolution;
	this->formatDescriptor = formatDescriptor;
	this->qualitySpec = qualitySpec;
	type = "Video";
}


Video::~Video() {}

bool Video::ReadData(std::istream& in) {
	Media::ReadData(in);
	in.ignore();
	getline(in, resolution);
	getline(in, formatDescriptor);
	getline(in, qualitySpec);
	return true;
}


bool Video::WriteData(std::ostream& out) {
	Media::WriteData(out);
	out << resolution << std::endl;
	out << formatDescriptor << std::endl;
	out << qualitySpec << std::endl;
	out << "***************************************" << std::endl;
	return true;
}


std::string Video::getType() const {
	return type;
}