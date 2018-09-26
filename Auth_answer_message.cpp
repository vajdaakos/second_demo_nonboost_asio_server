#include "Auth_answer_message.h"

Auth_answer_message::Auth_answer_message(unsigned int message_id,std::string response_string)
{
	set_type(15);
	set_response_to(message_id-1);
	set_sender("server");
	set_full_path("default");
	set_seq(message_id);
	
	this->body_lenght=response_string.length()+1;
	set_body(response_string);
	
}

Auth_answer_message::~Auth_answer_message()
{
}

