The API: int read4(char *buf) reads 4 characters at a time from a file.

The return value is the actual number of characters read. For example, it returns 3 if there is only 3 characters left in the file.

By using the read4 API, implement the function int read(char *buf, int n) that reads n characters from the file.

Note:
The read function may be called multiple times.

// Forward declaration of the read4 API.
int read4(char *buf);

class Solution {
public:
    /**
     * @param buf Destination buffer
     * @param n   Maximum number of characters to read
     * @return    The number of characters read
     */
    char buf4[4];
    int i4=0; n4=0;
    int read(char *buf, int n) {
        int i = 0;
        while( i<n && (i4 < n4 || (i4=0) < ( n4 = read4(buf4) ) ) ) {
            buff[i++] = buf4[i4++];
        }
        return i;
    }
};