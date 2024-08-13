#include <libssh/libssh.h>
#include <stdlib.h>
#include <stdio.h>

int main(){
    ssh_session first_session = ssh_new();
    // setting up ssh_options_set()
    // some important variables
    int verbosity = SSH_LOG_PROTOCOL; // why is it a int?  
    int port = 22; // client machine or server machine?
    // worst case
    if(first_session == NULL) {
        exit(-1);
    }
    // set options
    ssh_options_set(first_session, SSH_OPTIONS_HOST, "localhost"); // this is mandatory
    ssh_options_set(first_session, SSH_OPTIONS_LOG_VERBOSITY, &verbosity); // why pointer is used here?
    ssh_options_set(first_session, SSH_OPTIONS_PORT, &port);

    printf("hello");
    ssh_free(first_session);
}