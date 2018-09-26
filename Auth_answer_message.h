#ifndef AUTH_ANSWER_MESSAGE_H
#define AUTH_ANSWER_MESSAGE_H
#include "Message.h"
class Auth_answer_message: public Message
{
public:
	Auth_answer_message(unsigned int,std::string);
	~Auth_answer_message();

};

#endif // AUTH_ANSWER_MESSAGE_H
