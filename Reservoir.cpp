#include "Reservoir.h"
#include <cstring>
using namespace std;

Reservoir::Reservoir() : name("sss"), type("ooo"), width(0.0), length(0.0), maxDepth(0.0) {}

Reservoir::Reservoir(const string& name, const string& type, double width, double length, double maxDepth)
    : name(name), type(type), width(width), length(length), maxDepth(maxDepth) {}

Reservoir::Reservoir(const Reservoir& other)
    : name(other.name), type(other.type), width(other.width), length(other.length), maxDepth(other.maxDepth) {}

Reservoir& Reservoir::operator=(const Reservoir& other) {
    if (this != &other) {
        name = other.name;
        type = other.type;
        width = other.width;
        length = other.length;
        maxDepth = other.maxDepth;
    }
    return *this;
}

Reservoir::~Reservoir() {}

double Reservoir::calculateVolume() const {
    return width * length * maxDepth;
}

double Reservoir::calculateSurfaceArea() const {
    return width * length;
}

bool Reservoir::isSameType(const Reservoir& other) const {
    return type == other.type;
}

bool Reservoir::isLargerSurfaceArea(const Reservoir& other) const {
    return isSameType(other) && calculateSurfaceArea() > other.calculateSurfaceArea();
}

const string& Reservoir::getName() const {
    return name;
}

const string& Reservoir::getType() const {
    return type;
}

void Reservoir::setName(const string& name) {
    this->name = name;
}

void Reservoir::setType(const string& type) {
    this->type = type;
}

void Reservoir::setDimensions(double width, double length, double maxDepth) {
    this->width = width;
    this->length = length;
    this->maxDepth = maxDepth;
}

void Reservoir::display() const {
    cout << "name: " << name << ", type: " << type
        << ", width: " << width << ", length: " << length
        << ", max depth: " << maxDepth << endl;
}

void Reservoir::writeToTextFile(FILE* file) const {
    fprintf(file, "%s\n%s\n%f\n%f\n%f\n", name.c_str(), type.c_str(), width, length, maxDepth);
}

void Reservoir::writeToBinaryFile(FILE* file) const {
    size_t nameLen = name.size();
    size_t typeLen = type.size();
    fwrite(&nameLen, sizeof(nameLen), 1, file);
    fwrite(name.c_str(), sizeof(char), nameLen, file);
    fwrite(&typeLen, sizeof(typeLen), 1, file);
    fwrite(type.c_str(), sizeof(char), typeLen, file);
    fwrite(&width, sizeof(width), 1, file);
    fwrite(&length, sizeof(length), 1, file);
    fwrite(&maxDepth, sizeof(maxDepth), 1, file);
}

void Reservoir::readFromBinaryFile(FILE* file) {
    size_t nameLen, typeLen;
    fread(&nameLen, sizeof(nameLen), 1, file);
    char* nameBuffer = new char[nameLen + 1];
    fread(nameBuffer, sizeof(char), nameLen, file);
    nameBuffer[nameLen] = '\0';
    name = nameBuffer;
    delete[] nameBuffer;

    fread(&typeLen, sizeof(typeLen), 1, file);
    char* typeBuffer = new char[typeLen + 1];
    fread(typeBuffer, sizeof(char), typeLen, file);
    typeBuffer[typeLen] = '\0';
    type = typeBuffer;
    delete[] typeBuffer;

    fread(&width, sizeof(width), 1, file);
    fread(&length, sizeof(length), 1, file);
    fread(&maxDepth, sizeof(maxDepth), 1, file);
}
