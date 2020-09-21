## Test list for Circular buffer

- Init test - number of available data is zero, size of buffer (maximum number of entries)
- Writing the buffer increases the number of data, but the data can't go beyond the size of the buffer
- Reading is to reduce the number of elements available, should not go below zero
- Check maximum writes to circular buffer - error
- Check maximum reads to circular buffer - error
- Pointers to point the current available data (absolute address) 
- Pointers (Address are not be NULL)
- Init of buffer data should be zero
- Data should not overflow unsigned int types



