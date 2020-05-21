#include <csv_engine.h>
#include <bits/stdc++.h>
#include <map>
#include <thread>
#include <algorithm>
#include <iterator>
#include <xlsx2string.h>
typedef std::string vertex;
typedef std::string vertex_label;
typedef std::string metex;
typedef std::string metex_label;
typedef std::pair<vertex,vertex> edge;
typedef std::pair<vertex,metex> link;


typedef std::set<vertex_label> vertex_labels;
typedef std::map<vertex_label,std::set<vertex>> vertices;
typedef std::map<metex_label,std::set<metex>> metices;
typedef std::map<vertex_label,std::set<metex_label>> metex_labels;
typedef std::map<std::pair<vertex,metex_label>,std::set<metex>> links;
typedef std::map<std::pair<vertex,vertex_label>,std::set<vertex>> edges;
//typedef std::map<std::pair<edge,metex_label>,std::set<metex>>
//typedef std::map<std::pair<std::pair<std::string,std::string>,std::string>,std::string> edge_metadata;


//#include <database_engine>
//#typedef std::pair<std::string,std::string> dpair;

//typedef	std::map<std::string,std::set<std::string> >  tables;
//typedef	std::map<std::string,int>  keys;


//typedef std::map<std::string&,std::set<std::string&> > vertex_labels
//typedef std::map<std::string&,std::set<std::string&> > label_vertices
//typedef std::map<std::pair<std::string&,std::string&>,std::set<std::string&> > edges
/*
typedef std::set<std::string> vertices;
typedef std::set<std::string> label;

typedef std::map<std::string,int> item_int;
typedef std::map<int,std::string> int_item;
typedef std::map<std::pair<int,int>,int> connections;
typedef std::map<std::string,int> class_int;
typedef std::map<int,std::string> int_class;


void build_db(csv_file& A,class_int &B,int_class &BB)
{

for(int j=1;j<A.Ncols();j++){
B[A.cell(1,j)]=B.size()+1;
BB[B.size()]=A.cell(1,j);
//E.insert(std::make_pair(A.cell(1,j),E.size()+1);
//E.insert(std::make_pair(A.cell(1,j),E.size()+1);
}

}

void ingest(csv_file&  test,tables & p,
std::set<std::string>& test2,tables & p1,tables & p3,
std::map<std::pair<std::string,std::string>,std::set<std::string> > & p4)
{

std::set<std::string> temp;
for(int i=1;i<=test.Nrows();i++){

for(int j=1;j<=test.Ncols();j++){
//p.insert(std::make_pair(test.cell(1,j),test.cell(i,j)));
if(i==1){test2.insert(test.cell(1,j));}
//temp.insert(test.cell(i,j));
//p[test.cell(i,1)].insert(test.cell(i,j));
p3[test.cell(1,j)].insert(test.cell(i,j));
p1[test.cell(i,1)].insert(test.cell(1,j));
p4[std::pair<std::string,std::string>(test.cell(i,1),test.cell(1,j))].insert(test.cell(i,j));
}


//p.insert(std::pair<std::string,std::set<std::string>>(test.cell(i,1),temp));
//p[test.cell(i,1)]=temp;
//std::cout<<test.cell(i,1)<<" "<<temp.size()<<" "<<p[test.cell(i,1)].size()<<std::endl;
//temp.clear();
}
}
*/
//void ingest(csv_file&  test,keys& p)
//{
//test.check();
//test.status();

//test.print();

//for(int j=1;j<=test.Ncols();j++){
//for(int i=1;i<=test.Nrows();i++){
//p.insert(std::make_pair(test.cell(i,j),p.size()+1));
//std::cout<<i<<" "<<j<<" ";
//std::cout<<test.cell(i,j)<<std::endl;
//}
//}
//p.insert(std::pair<std::string,std::set<std::string>>(test.cell(i,1),temp));
//p[test.cell(i,1)]=temp;
//std::cout<<test.cell(i,1)<<" "<<temp.size()<<" "<<p[test.cell(i,1)].size()<<std::endl;
//temp.clear();
//}


/*

double set_match(std::set<std::string>&A,std::set<std::string> &B)
{
std::set<std::string> C;
std::set_intersection(A.begin(),A.end(),B.begin(),B.end(),std::inserter(C, C.begin()));
if(A.size()>=B.size()){
return(C.size()/B.size());}
else{return(C.size()/A.size());}


}
*/


class database
{
public:


std::map<std::string,std::string>	synonyms;
metices Metices;
metex_labels Mcluster;
vertex_labels Cluster;
vertices Vertices;
edges Edges;
links Links;
private:



};


void ingest(csv_file& file,vertex_labels& tower,vertices& elements,metex_labels& metadata, metices& md, edges& eg,links& li, int col){
//for(int i=1;i<=software.Ncols();i++)
//{


if(col==1){
std::string header=file.cell(1,col);	
tower.insert(header);
for(int j=2;j<=file.Nrows();j++)
{
elements[header].insert(file.cell(j,col));

}

}


if(file.cell(1,col)[0]=='@'){
std::string header1=file.cell(1,col);
//std::string header(file.cell(1,col).begin()+1,file.cell(1,col).end());
//std::string header(file.cell(1,col).begin()+1,file.cell(1,col).end());	
std::string header(header1.begin()+1,header1.end());

//std::cout<<header<<std::endl;
tower.insert(header);
for(int j=2;j<=file.Nrows();j++)
{
elements[header].insert(file.cell(j,col));
eg[std::make_pair(file.cell(j,1),header)].insert(file.cell(j,col));
}
}
else if(col!=1)
{
std::string header=file.cell(1,col);	
metadata[file.cell(1,1)].insert(header);

for(int j=2;j<=file.Nrows();j++)
{
li[std::make_pair(file.cell(j,1),header)].insert(file.cell(j,col));
//md[header].insert(file.cell(j,col));
}

}
}

void consume(csv_file& file,vertex_labels& tower,vertices& elements,metex_labels& metadata, metices& md, edges& eg,links& li,std::map<std::string,std::string>	synonyms)
{
int k=0;
int l=0;	
std::vector<int> order;	
for(int i=1;i<=file.Ncols();i++)
{auto test=synonyms[file.cell(1,i)];
if(test==""){std::cout<<"error";}
if(tower.find(test)==tower.end()){if(metadata.find(test)==metadata.end()){}}
else{k++;order.push_back(k);}
}


}





int main()
{
std::map<std::string,std::string>	synonyms;
metices md;
metex_labels mtower;
vertex_labels tower;
vertices elements;
edges eg;
edges li;

tower.insert("SOFTWARE_NAME");
tower.insert("COMPANY");

char file1[]="software.csv";
csv_file software(file1);

char file2[]="company.csv";
csv_file company(file2);








//ingest(software,tower,elements,mtower,md,eg,li,1);
ingest(software,tower,elements,mtower,md,eg,li,2);
ingest(software,tower,elements,mtower,md,eg,li,3);
ingest(software,tower,elements,mtower,md,eg,li,4);
ingest(software,tower,elements,mtower,md,eg,li,5);



for(auto itr:eg[std::make_pair("Test1","COMPANY")]){std::cout<<itr<<std::endl;}
for(auto itr:eg[std::make_pair("Access Control Infrastructure","COMPANY")]){std::cout<<itr<<std::endl;}
for(auto itr:li[std::make_pair("ABO","SGATE@COMPANY")]){std::cout<<itr<<std::endl;}
//std::cout<<eg[std::make_pair("Test2","COMPANY")];

//tables *testr=new tables[10];
//csv_file *ads=new csv_file[10];
//keys key;

//std::set<std::string> datas;
//std::string hallo="files.xlsx";

/*
char file[]="files.csv";
csv_file A(file);


for(int k=1;k<=A.Nrows();k++)
{

char *arr=new char[A.cell(k,1).length()+1];
strcpy(arr, A.cell(k,1).c_str()); 

auto iter=A.cell(k,1).end();
iter--;
while(*iter!='.' && iter!=A.cell(k,1).begin())
{
iter--;
}

std::string fileend(iter,A.cell(k,1).end());


std::cout<<arr<<std::endl;
if(fileend==".csv"){csv_file C(arr);C.uppercase();C.status();}
if(fileend==".xlsx"){auto CC= xlsx2string(arr);
csv_file NN(CC[1]);
NN.repair();
NN.uppercase();
NN.status();
//std::cout<<CC[1];
}

delete[] arr;



}




//char fi[]="1.xlsx";





//NN.write("asd.csv");
//ingest(NN,key);
//std::cout<<key["DAT"]<<" "<<"DAT"<<std::endl;
//std::cout<<key["FIRST-BUS-CLI"]<<" "<<"FIRST-BUS-CLI"<<std::endl;

//csv_file *C=new csv_file[A.Nrows()];
/*
csv_file B(arr);
for(int k=1;k<A.Nrows();k++){
if(k!=2 && k!=138){	
//std::cout<<k<<" "<<A.cell(k,2)<<std::endl;
std::cout<<k<<" ";
arr=new char[A.cell(k,2).length()+1];
strcpy(arr, A.cell(k,2).c_str()); 
//csv_file B(arr);
B=csv_file(arr);
std::cout<<B.Ncols()<<" "<<B.Nrows()<<" "<<all.size()<<std::endl;
//B.clean();
ingest(B,all,datas,vertex_labels,label_vertices,vertex_vertices);
delete[] arr;}
}
std::cout<<pairs.size()<<std::endl;

std::set<std::pair<std::string,std::string > >::iterator  iter;
for(iter=pairs.begin();iter!=pairs.end();iter++){
std::cout<<iter->first<<"   "<<iter->second<<std::endl;

}
//B.check();
//B.status();
//A.print();
//
//
int summe=0;
std::set<std::string>::iterator  iters;
for(iters=datas.begin();iters!=datas.end();iters++){
//std::cout<<iters->length()*sizeof(char)<<std::endl;
	std::cout<<*iters<<std::endl;
	summe+=iters->length();
}
std::map<std::string,std::set<std::string>>::iterator  iterss;
for(iterss=all.begin();iterss!=all.end();iterss++){
//std::cout<<iters->length()*sizeof(char)<<std::endl;
	std::cout<<iterss->first<<" "<<iterss->second.size()<<std::endl;
}


//std::cout<<summe/datas.size()<<" "<<all.size()<<std::endl;
//B.clean();
int i,j;
std::string h;
std::set<std::string> help;

while(0==0)
{
//std::cin>>i;
std::cin>>h;
//std::cout<<B.cell(i,j)<<std::endl;

//	h=B.cell(i,j);
//for(int k=0;k<h.length();k++){
//	std::cout<<int(h[k])<<" ";
std::cout<<label_vertices[h].size()<<std::endl;
for(iters=label_vertices[h].begin();iters!=label_vertices[h].end();iters++){
	std::cout<<*iters<<std::endl;


			}

}
	
std::cout<<std::endl<<pairs.size()<<"  "<<sizeof(paairs)<<std::endl;
std::set<std::pair<std::string,std::string > >::iterator iter;
//std::pair
//database all;
csv_file test0("files.csv");
std::cout<<test0.cell(1,1)<<std::endl;
csv_file test("2_01_APPLICATION.csv");

for(int i=1;i<=test.Nrows();i++){
//std::cout<<i<<" ";

for(int j=1;j<=test.Ncols();j++){


auto iters=pairs.insert(std::make_pair(test.cell(1,j),test.cell(i,j)));
iter=iters.first;
std::cout<<iter->second<<std::endl;
}
}

std::cout<<std::endl<<pairs.size()<<"  "<<sizeof(pairs)<<std::endl;
*/



}
