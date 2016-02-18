#include <fstream>
#include "Output.h"
#include "StreamOutput.h"
#include "LineOutput.h"
#include "NumberedOutput.h"
#include "TeeOutput.h"
#include "FilterOutput.h"

int main()
{
	std::string line;
	std::string file;
	std::string tees;
	std::string filt;
	std::ofstream oust;
	std::ofstream teeOust;

	// Introducing the program and getting file name/opening it 
	std::cout << "Welcome to a text decorator. \nPlease enter the name of a file you would like to decorate: ";
	std::getline(std::cin, file);
	std::ifstream inst(file);

	// Check to see if file exists, if it does, opens up output file
	// Creates new Output<std::string> pointer and points it to 
	// SteamOutput instance that takes output file as a parameter
	if (inst.is_open())
	{
		oust.open("output.txt");
		Output<std::string> *output = new StreamOutput<std::string>(oust);
		std::string type = "placeholder";

		// If no input, exists loop
		while(type != ""){
			std::cout << "What decorators do you want? (1 - LineOutput, 2 - NumberedOutput, 3 - TeeOutput, 4 - FilterOutput, hit enter for exit): ";
			std::getline(std::cin, type);
			if (type == "1") {
				output = new LineOutput<std::string>(output);
			}
			if (type == "2") {
			 	output = new NumberedOutput<std::string>(output);
			}
			if (type == "3"){
				// Pseudo-flag to check if secondary write file 
				// Has been created; if so, doesn't decorate
				if(tees == "") {
					std::cout << "Please enter file name you would like to write to: ";
					std::getline(std::cin, tees);
					teeOust.open(tees);
					if(teeOust.is_open()) {
						output = new TeeOutput<std::string>(output, teeOust);
					}
				}
				else {
					std::cout << "Can only write to 1 additional file" << std::endl;
				}
			}
			if (type == "4") {
				// This filter options gives 2 filter choices
				std::cout << "Which filter do you want? (1 - ContainsHash, 2 - Contains10WordsOrLess): ";
				std::getline(std::cin, filt);
				if(filt == "1" || filt == "2") {
					output = new FilterOutput<std::string>(output, filt);
				}
			}
		}

		// After everything is said and done, write to file(s)
		while (getline(inst, line))
		{
			output->write(line);
		}

		inst.close();
		oust.close();
	} 
	else { 
		std::cout << "Unable to open file" << std::endl; 
	}
}
