#include <libssh/libssh.h>
#include <stdlib.h>
#include <stdio.h>

int main(){
    // first task is to create ssh session
    ssh_session user_session = ssh_new();
    if(user_session == NULL){
        exit(-1);
    }
    // env vars
    int verbosity = SSH_LOG_PROTOCOL;
    int port = 8001;
    // setting up options
    ssh_options_set(user_session, SSH_OPTIONS_HOST, "localhost");
    // ssh_options_set(user_session, SSH_OPTIONS_LOG_VERBOSITY, &verbosity);
    ssh_options_set(user_session, SSH_OPTIONS_PORT,&port);
    // connecting to server
    int rc = ssh_connect(user_session);
    if(rc != SSH_OK){
        ssh_get_error(user_session);
        printf("not connected");
        exit(-1);
    }

    printf("connected");
    ssh_disconnect(user_session);
    ssh_free(user_session);


}