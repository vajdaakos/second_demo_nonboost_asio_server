#ifndef CLOSE_CONNECTION_H
#define CLOSE_CONNECTION_H
#include "Message.h"
class close_connection: public Message
{
public:
	close_connection(unsigned int);
	~close_connection();

};

#endif // CLOSE_CONNECTION_H
