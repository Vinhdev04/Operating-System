 /* producer.c */
 #include"unistd.h"
 #include"stdio.h"
 #include"stdlib.h"
 #include"string.h"
 #include"fcntl.h"
 #include"limits.h"
 #include"sys/types.h"
 #include"sys/stat.h"
 #define FIFO_NAME "my_fifo"
 #define BUFFER_SIZE PIPE_BUF
 #define TEN_MEG (1024 * 1024 * 10)
 int main() {
 	int pipe_fd;
 	int res;
 	int open_mode = O_WRONLY;
 		int bytes_sent = 0;
 		char buffer[BUFFER_SIZE + 1];
 	if(access(FIFO_NAME, F_OK) == -1)
 	{
 		res = mkfifo(FIFO_NAME, (S_IRUSR | S_IWUSR));
 		if( res != 0)
 	  {
 	  	fprintf( stderr, "FIFO object not created [%s]\n", FIFO_NAME);
 	  	exit(EXIT_FALLURE);
	   }
	 }
	 
	 printf("Process %d starting to write on pipe\n", getpid() );
	 pipe_fd = open(FIFO_NAME, open_mode);
	 if(pipe_fd != -1)
  {
	 while(bytes_sent < TEN_MEG)
	 {
	 	res = write(pipe_fd, buffer, BUFFER_SIZE);
	 	if(res == -1)
	   {
	   	fprintf(stderr, "Write error on pipe\n");
	   	exit(EXIT_FALLURE);
	   	
	   }
	   bytes_sent += res;
	 	
	 }
	 (void) close(pipe_fd);
  }
  else
  {
  	exit(EXIT_FALLURE);
  }
  printf("Process %d finished, %d bytes sent\n", getpid(),bytes_sent);
  exit(EXIT_SUCCESS);
 }
