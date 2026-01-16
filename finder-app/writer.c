#include "stdlib.h"
#include "string.h"
#include "errno.h"
#include "fcntl.h"
#include "unistd.h"
#include "syslog.h"

int main(int argc, char *argv[])
{
    openlog("writer", 0, LOG_USER);

    if(argc < 3)
    {
        syslog(LOG_ERR, "Parameters not specified");
        closelog();
        return 1;
    }

    const char *writefile = argv[1];
    const char *writestr = argv[2];

    syslog(LOG_DEBUG, "Writing %s t %s", writestr, writefile);

    int fd = open(writefile, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd == -1)
    {
        syslog(LOG_ERR, "Failed to open file %s: %s", writefile, strerror(errno));
        close(fd);
        closelog();
        return 1;
    }

    ssize_t written = write(fd, writestr, strlen(writestr));
    if(written == -1)
    {
        syslog(LOG_ERR, "Failed to write to file %s: %s", writefile, strerror(errno));
        close(fd);
        closelog();
        return 1;
    }

    close(fd);
    closelog();
    return 0;
}