#include <csv_engine.h>
#include <bits/stdc++.h> 
//#include <database_engine>
//#typedef std::pair<std::string,std::string> dpair;



void ingest(csv_file&  test,std::set<std::pair<std::string,std::string > > & p)
{

for(int i=1;i<=test.Nrows();i++){
for(int j=1;j<=test.Ncols();j++){
p.insert(std::make_pair(test.cell(1,j),test.cell(i,j)));

}
}




}



int main()
{
std::pair<std::string,std::string > paairs;
std::set<std::pair<std::string,std::string > > pairs;
std::string hallo="test.csv";
char *arr=new char[hallo.length()+1];
strcpy(arr, hallo.c_str()); 
csv_file A(arr);
//csv_file *C=new csv_file[A.Nrows()];

csv_file B(arr);
for(int k=1;k<A.Nrows();k++){
if(k!=2 && k!=138){	
//std::cout<<k<<" "<<A.cell(k,2)<<std::endl;
std::cout<<k<<" ";
arr=new char[A.cell(k,2).length()+1];
strcpy(arr, A.cell(k,2).c_str()); 
//csv_file B(arr);
B=csv_file(arr);
std::cout<<B.Ncols()<<" "<<B.Nrows()<<std::endl;
ingest(B,pairs);
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
B.clean();
int i,j;
std::string h;
while(0==0)
{
std::cin>>i;
std::cin>>j;
std::cout<<B.cell(i,j)<<std::endl;

	h=B.cell(i,j);
for(int k=0;k<h.length();k++){
	std::cout<<int(h[k])<<" ";


			}

}
	/*
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
