#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iomanip>
#include "player.h"

int main(int argc, char *argv[])
{
  std::string inputFile;
  std::ifstream fin;
  std::vector<player> batter;
  std::string firstName;
  std::string lastName;
  player temp;
  unsigned int totalBases;

  if(argc == 2)
    inputFile = argv[1];
  
  fin.open(inputFile);

  while(fin >> firstName >> lastName >> temp.atBats
	  >> temp.hits >> temp.doubles >> temp.triples
	>> temp.homeRuns >> temp.walks)
    {
      temp.name = firstName;
      temp.name += " ";
      temp.name += lastName;
      
      totalBases = (temp.doubles * 2 + temp.triples * 3 + temp.homeRuns *4) + (temp.hits - temp.doubles - temp.triples - temp.homeRuns);
      
      temp.runscreated = (float)((temp.hits + temp.walks)* totalBases)/(temp.atBats + temp.walks);
	
      batter.push_back(temp);
    }
  fin.close();

  for(unsigned int i = 0; i < batter.size(); i++)
    {
      std::cout << std::setw(20) << std::left
		<< batter[i].name 
		<< batter[i].runscreated << std::endl;
    }  
  return 0;
}
