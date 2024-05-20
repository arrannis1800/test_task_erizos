# test_task_erizos

## CPP part
Everything compiles with this command without any warnings
`g++ -Wall -Wextra -Wpedantic test_task_erizos.cpp -o test -std=c++14`

### ParseInt
I made a few copies of this function 
ParseInt1 uses std::strings and math library because it matches more accurately with the test task
ParseInt2 uses c-style strings and in my opinion, it works faster in this case


### SpiralPrint
This part I made this using printf to display the result, but I'm not sure that it is the expected way to result value
I found this problem on leetcode and found out that my result was memory efficient and average in runtime
[leetcode problem #54](https://leetcode.com/problems/spiral-matrix/submissions/1261214845)

![image](https://github.com/arrannis1800/test_task_erizos/assets/52630886/4c6da6a5-4e48-4782-9d23-b8dab96bf8c7)

I'm not sure that my decision was correct, but I think that memory is preferable when we use quite big objects like media


## UE4 part

Setting the location and resizing the plane works well, the margins are set correctly. Build works on Windows 
