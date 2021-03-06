#include <MacTCP.h>

#include "irc.h"
#include "netutil.h"

static const char *message_types[] = { "PRIVMSG", "NOTICE" };

void send_userinfo(StreamPtr stream, const char *nick, const char *ident, const char *realname)
{
	swritef(stream, "NICK %s\r\n", nick);
	swritef(stream, "USER %s * * :%s\r\n", ident, realname);
}

void send_pong(StreamPtr stream, const char *token)
{
	swritef(stream, "PONG :%s\r\n", token);
}

void send_join(StreamPtr stream, const char *channel)
{
	swritef(stream, "JOIN %s\r\n", channel);
}

void send_part(StreamPtr stream, const char *channel)
{
	swritef(stream, "PART %s\r\n", channel);
}

void send_message(StreamPtr stream, int type, const char *target, const char *message)
{
	swritef(stream, "%s %s :%s\r\n", message_types[type], target, message);
}