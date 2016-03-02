#include <iostream>
#include <fstream>
void loadData(){
	std::string temp;
	std::string path="/sdcard/Games/com.mojang/FCAddon/addid.txt";
	std::ifstream file(path);
	if(file.fail()){
		std::ofstream stream(path);
		if(!stream) {
			return;
		}
		stream<<"WireID="<<std::endl<<"PipeID=";
		stream.close();
	}
	std::ifstream stream(path);
	while(stream.good()) {
		std::string wire;
		std::string pipe;
		std::getline(stream,temp);
		if(temp.find("WireID=")!=std::string::npos){
			wire=temp.substr(temp.find("=")+1);
		}else if(temp.find("PipeID=")!=std::string::npos){
			pipe=temp.substr(temp.find("=")+1);
		}
	}
	stream.close();
}

#include <iostream>
 
template
<   
    typename TYPE,
    std::size_t SIZE
>
std::size_t array_length(const TYPE (&)[SIZE])
{   
	return SIZE;
}