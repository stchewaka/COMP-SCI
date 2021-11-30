#ifndef MEDIA_H
#define MEDIA_H

#include <string>
#include <fstream>

class Media {
protected:
	std::string uniqueID;
	std::string name;
	int runningTime;

public:
	Media();
	Media(std::string uniqueID, std::string name, int runningTime);
	~Media();
	void setUniqueID(std::string uniqueID);
	void setName(std::string name);
	void setRunningTime(int runningTime);
	std::string getUniqueID() const;
	std::string getName() const;
	int getRunningTime() const;
	virtual std::string getType() const = 0;
	virtual bool ReadData(std::istream& in);
	virtual bool WriteData(std::ostream& out);
};

#endif // !MEDIA_H
