#include "close_connection.h"

close_connection::close_connection(unsigned int message_id)
{
	set_type(11);
	set_response_to(0);
	set_sender("server");
	set_full_path("default");
	set_seq(message_id);
	
	this->body_lenght=0;
	//set_body(response_string);
}

close_connection::~close_connection()
{
}

