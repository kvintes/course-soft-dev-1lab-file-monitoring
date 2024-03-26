#include "TestFile.h"
#include "File.h"
#include <iostream>
using namespace std;

TestFile::TestFile() {}
void TestFile::testEmpty(){
    File a;
    std::cout<<"test empty string in constructor"<<std::endl;
    cout<<"a size: "<<a.getSize()<<endl;
    cout<<"a exists status: "<<a.getExistsStatus()<<endl;
    cout<<"a path: "<<a.getPath().toStdString()<<endl;
}
