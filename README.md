# get_next_line 소개
newline 으로 이루어진 text file을 한 줄 씩 읽어들이는 function를 구현합니다
(text file 데이터를 한 줄씩 가져와 데이터를 parsing하기 위함)

# get_next_line 형태

<리턴값>
* 1  : 한 라인이 읽혔을 때 (개행문자를 만남)
* 0  : 파일의 끝 EOF에 도달했을 때
* -1 : 에러가 발생 했을 때

<리턴값이 -1이 나오는 경우>
1) fd값이 0보다 작을 때
2) read() 리턴값이 -1일 때
3) BUFFER_SIZE 값이 0이거나 음수일 때

  // 한 라인을 읽어왔을 때, 읽어들인 라인에 '\n' 문자가 있으면 안됨

# get_next_line 사용예제
```c
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
int main(void)
{
	int fd;
	int ret;
	char *line;  // 읽어들일 한 줄이 담겨있는 메모리를 가리킬 포인터
  
  if (!(fd = open("files/alphabet", O_RDONLY)))
	{
		printf("\nError in open\n");
		return (1);
	}
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		printf("|%s\n", line);
    free(line);
	}
	printf("|%s\n", line);
	free(line);
  
	close(fd);
	return (0);
}
```
