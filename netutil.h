#ifndef NETUTIL_H
#define NETUTIL_H

#include <MacTypes.h>
#include <MacTCP.h>

OSErr swritef(StreamPtr stream, const char *fmt, ...);
void spoll(StreamPtr stream, void (*process_line)(char *));

#endif