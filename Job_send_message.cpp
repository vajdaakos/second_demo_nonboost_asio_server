#include "Job_send_message.h"
#include <iostream>
#include <fstream>
#include <memory>
Job_send_message::Job_send_message(unsigned int message_id,unsigned int response_to_,std::vector<std::string> &jobs_with_path)
:jobs_with_path(jobs_with_path)
{
	set_type(4);
	set_response_to(response_to_);
	set_sender("server");
	
	set_seq(message_id);
	set_body_from_jobfile();
	
}

Job_send_message::~Job_send_message()
{
}

void Job_send_message::set_body_from_jobfile()
{
	//std::ifstream jobfile;
	if(!jobs_with_path.empty())
	{
		std::streampos begin,end;
		
		std::string jobfullname=jobs_with_path.front();
		std::ifstream jobfile (jobfullname, std::ios::in | std::ios::binary|std::ios::ate);
		if(jobfile.is_open())
		{
			end = jobfile.tellg();
			jobfile.seekg (0, std::ios::beg);
			begin = jobfile.tellg();
			int size=end-begin;
			//size = jobfile.tellg();
			char temp[size];
			body=(unsigned char*)malloc(size);
			jobfile.seekg (0, std::ios::beg);
			jobfile.read (temp, size);
			jobfile.close();
			memcpy(body,temp,size);
			set_full_path(jobfullname);
			
			set_body_lenght(size);
			jobs_with_path.erase(jobs_with_path.begin());
		}
	}
}