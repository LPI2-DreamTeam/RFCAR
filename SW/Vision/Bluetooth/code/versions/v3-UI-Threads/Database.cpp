/**
 * @file Database.cpp
 * @author Jose Pires
 * @date 04-06-2019
 *
 * @brief Implementation for database module
 */

#include "Database.h"
#include <fstream>
#include <stdexcept>

using std::runtime_error;
using std::ios;
using std::endl;

#define SETTINGS_FNAME "sett.dat"
#define LOG_FNAME "/home/pedro/BTChat/log.dat"

Database::Database(const string &fname)
{
/* Open settings for read: beginning of the file */
   /*setFile = new ifstream(SETTINGS_FNAME);

   if(setFile == nullptr)
   {
       s = "Settings file (" + string(SETTINGS_FNAME) + ") cannot be opened!";
       throw runtime_error(s);
   }*/
/* Open settings for read: beginning of the file (for read) and append (to write)*/
   string s;
   logFile = new fstream(fname, ios::in | ios::app);
   if(logFile == nullptr)
   {
       s = "Log file (" + fname + ") cannot be opened!";
       throw runtime_error(s);
   }
}

Database::~Database(){}

void Database::write(const string &s)
{
/* No need to check, because it aborts construction */
//   if(logFile == nullptr)
//   {
//       string str = "Log file (" + string(LOG_FNAME) + ") cannot be written!";
//       throw runtime_error(str);
//   }
   (*logFile) << s << endl;
}

string Database::history()
{
    string line = "";
    getline(*logFile, line);
    logFile->clear();
    return line;
}

string Database::load()
{
 //  if(logFile == nullptr)
 //  {
 //      string str = "Log file (" + string(LOG_FNAME) + ") cannot be written!";
 //      throw runtime_error(str);
 //  }
    string line = ""; 
    //while( getline(*setFile, line) )
    //    ;//line += "\n";
   
   getline(*setFile, line);
   return line; 
}
