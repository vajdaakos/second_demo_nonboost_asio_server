#ifndef JOB_SEND_MESSAGE_H
#define JOB_SEND_MESSAGE_H
#include "Message.h"
#include <string>
#include <vector>
class Job_send_message : public Message
{
public:
	Job_send_message(unsigned int,unsigned int,std::vector<std::string>&);
	~Job_send_message();
private:
	void set_body_from_jobfile();
	std::vector<std::string>& jobs_with_path;

};

#endif // JOB_SEND_MESSAGE_H
