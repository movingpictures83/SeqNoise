#include "PluginManager.h"
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include "SeqNoisePlugin.h"

void SeqNoisePlugin::input(std::string file) {
 inputfile = file;
 std::ifstream ifile(inputfile.c_str(), std::ios::in);
 while (!ifile.eof()) {
   std::string key, value;
   ifile >> key;
   ifile >> value;
   parameters[key] = value;
 }
}

void SeqNoisePlugin::run() {}

void SeqNoisePlugin::output(std::string file) {
 std::string outputfile = file;
 std::string myCommand = "";
myCommand += "SeqNoise";
myCommand += " ";
myCommand += "-in";
myCommand += " ";
myCommand += parameters["fastafile"];
myCommand += " ";
myCommand += "-din";
myCommand += " ";
myCommand += parameters["distfile"];
myCommand += " ";
myCommand += "-lin";
myCommand += " ";
myCommand += parameters["listfile"];
myCommand += " -rin";
myCommand += " ";
myCommand += parameters["lookupfile"];
myCommand += " ";
myCommand += "-out";
myCommand += " ";
myCommand += outputfile + " ";
myCommand += "-s";
myCommand += " ";
myCommand += parameters["s"];
myCommand += " ";
myCommand += "-c";
myCommand += " ";
myCommand += parameters["c"];
myCommand += " ";
myCommand += "-min";
myCommand += " ";
myCommand += parameters["mapfile"];
myCommand += " ";
 system(myCommand.c_str());
}

PluginProxy<SeqNoisePlugin> SeqNoisePluginProxy = PluginProxy<SeqNoisePlugin>("SeqNoise", PluginManager::getInstance());
