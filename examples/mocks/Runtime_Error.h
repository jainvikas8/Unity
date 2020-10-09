#ifndef _RUNTIME_ERROR_

    #define _RUNTIME_ERROR_

    void Runtime_error( const char *message, int parameter,
                        const char *file, int line);

    #define RUNTIME_ERROR(description, parameter)\
            Runtime_error (description, parameter, __FILE__, __LINE__);

#endif //_RUNTIME_ERROR_