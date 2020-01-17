#include <iostream>
#include <algorithm>
#include <string>
#include <vector>


class database 
{
public:

bool ingest(std::string);


	
private:	
#typedef std::map<std::string const&,std::vector<string const&> > table
#typedef std::map<std::pair<std::string const&,std::string const&>,std::pair<std::string const&,std::string const&>> link;
table dbase;
table dbase_tables;
table items;
table linked_items;
std::set<string> dbase_dump;
link item;
std::vector<std::string> link_types;

}


		




