#ifndef RESERVOIR_H
#define RESERVOIR_H
#include <iostream>
#include <string>
using namespace std;

class Reservoir {
    string name; 
    string type;
    double width;
    double length;
    double maxDepth;

public:
    Reservoir();
    explicit Reservoir(const string& name, const string& type, double width, double length, double maxDepth);
    Reservoir(const Reservoir& other);
    Reservoir& operator=(const Reservoir& other);
    ~Reservoir();

    double calculateVolume() const;
    double calculateSurfaceArea() const;
    bool isSameType(const Reservoir& other) const;
    bool isLargerSurfaceArea(const Reservoir& other) const;

    const std::string& getName() const;
    const std::string& getType() const;
    void setName(const std::string& name);
    void setType(const std::string& type);
    void setDimensions(double width, double length, double maxDepth);

    void display() const;

    void writeToTextFile(FILE* file) const;
    void writeToBinaryFile(FILE* file) const;
    void readFromBinaryFile(FILE* file);
};

#endif
