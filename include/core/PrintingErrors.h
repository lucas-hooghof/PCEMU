#pragma once

#include <stdint.h>
#include <stdio.h>

#define RED "\033[31m"
#define BLUE "\033[34m"
#define YELLOW "\033[33m"

#define RESET "\033[0m"

#define PRINT_ERROR(msg) printf("%s[ERROR]%s: %s\n",RED,RESET,msg)
#define PRINT_WARNING(msg) printf("%s[ERROR]%s: %s\n",YELLOW,RESET,msg)
#define PRINT_INFO(msg) printf("%s[INFO]%s: %s\n",BLUE,RESET,msg)

#define PRINT_ERROR_TAG(tag,msg) printf("%s[%s ERROR]%s: %s\n",RED,tag,RESET,msg)
#define PRINT_WARNING_TAG(tag,msg) printf("%s[%s WARNING]%s: %s\n",YELLOW,tag,RESET,msg)
#define PRINT_INFO_TAG(tag,msg) printf("%s[%s INFO]%s: %s\n",BLUE,tag,RESET,msg)