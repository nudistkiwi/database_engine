#include <iostream>
#include <algorithm>
#include <string>
#include <vector>


class database 
{
public:

//bool ingest(std::string);
add_item(std::string a,std::string b)
{
pairs.insert(std::make_pair(a,b));
};

	
private:	
//#typedef std::map<std::string const&,std::vector<string const&> > table
//#typedef std::map<std::pair<std::string const&,std::string const&>,std::pair<std::string const&,std::string const&>> link;
typedef std::pair<std::string,std::string> dpair;
//#typedef std::set<dpair> ;



//table dbases;
//table dbase_tables;
//table table_items;
//table item_items;
//link item;
//std::set<std::string> singles;
std::set<dpair> pairs;
//std::vector<std::string> link_types;

}


		




