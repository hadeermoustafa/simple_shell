#ifndef _SHELL_H_
#define _SHELL_H_
/**-----------------------------------*/
#include <limits.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <stdlib.h>
#include <sys/wait.h>
/**-------------------------------------*/
/** reading / write buffers ..*/

#define READ_BUF_SIZE 1024
#define BUF_FLUSH -1
#define WRITE_BUF_SIZE 1024
/**-------------------------------------*/
/** for command chaining..*/
#define CMD_AND		2
#define CMD_NORM	0
#define CMD_CHAIN	3
#define CMD_OR		1
/**------------------*/
/** for convert_number()..*/

#define CONVERT_LOWERCASE	1
#define CONVERT_UNSIGNED	2
/**--------------------------------------*/
/**1 if using system getline()..*/
#define USE_STRTOK 0
#define USE_GETLINE 0
/**--------------------------------------*/
#define HIST_MAX	4096
#define HIST_FILE	".simple_shell_history"
/**-------------------------------------*/
/**--------------------------------------*/
/**
 * struct liststr - singly linked list..
 * @num: the number field.
 * @str: a string.
 * @next: points to the next node..
 */
typedef struct liststr
{
	int num;
	char *str;
	struct liststr *next;
} list_t;

/**
 *struct passinfo - contains pseudo-arguements to pass into a function,
 *		allowing uniform prototype for function pointer struct
 *@arg: a string generated from getline containing arguements
 *@argv: an array of strings generated from arg
 *@path: a string path for the current command
 *@argc: the argument count
 *@line_count: the error count
 *@err_num: the error code for exit()s
 *@linecount_flag: if on count this line of input
 *@fname: the program filename
 *@env: linked list local copy of environ
 *@environ: custom modified copy of environ from LL env
 *@history: the history node
 *@alias: the alias node
 *@env_changed: on if environ was changed
 *@status: the return status of the last exec'd command
 *@cmd_buf: address of pointer to cmd_buf, on if chaining
 *@cmd_buf_type: CMD_type ||, &&, ;
 *@readfd: the fd from which to read line input
 *@histcount: the history line number count
 */
typedef struct passinfo
{
	char *arg;
	char **argv;
	char *path;
	int argc;
	unsigned int line_count;
	int err_num;
	int linecount_flag;
	char *fname;
	list_t *env;
	list_t *history;
	list_t *alias;
	char **environ;
	int env_changed;
	int status;

	char **cmd_buf; /* pointer to cmd ; chain buffer, for memory mangement */
	int cmd_buf_type; /* CMD_type ||, &&, ; */
	int readfd;
	int histcount;
} info_t;

#define INFO_INIT \
{NULL, NULL, NULL, 0, 0, 0, 0, NULL, NULL, NULL, NULL, NULL, 0, 0, NULL, \
	0, 0, 0}

/**
 *struct builtin - contains a builtin string and related function
 *@type: the builtin command flag
 *@func: the function
 */
typedef struct builtin
{
	char *type;
	int (*func)(info_t *);
} builtin_table;


/** looping.c*/
int hsh(info_t *, char **);
int find_builtin(info_t *);
void find_cmd(info_t *);
void fork_cmd(info_t *);

/**is_cmd.c*/
int is_exe(info_t *, char *);
char *double_chars(char *, int, int);
char *cmd_path(info_t *, char *, char *);

/**loophsh.c */
int loophsh(char **);

/** err.c */
void printINstr(char *);
int ePutCharacter(char);
int ePutfiled(char x, int file_d);
int ePutsfiled(char *str, int file_d);

/** str_length.c*/
int str_length(char *);
int compare_str(char *, char *);
char *begins_with(const char *, const char *);
char *str_conc(char *, char *);

/**str_copy.c*/
char *cpy_str(char *, char *);
char *doub_str(const char *);
void prt_input(char *);
int _putchar(char);

/**out.c */
char *stringcpy(char *, char *, int);
char *conc2String(char *, char *, int);
char *locChar(char *, char);

/**split_str.c*/
char **s_to_word(char *, char *);
char **s_to_word22(char *, char);

/** reallocate.c */
char *set_memory(char *, char, unsigned int);
void freestr(char **);
void *reallocate(void *, unsigned int, unsigned int);

/** free_pointer.c*/
int give_space(void **);

/** conv_in_stroi.c */
int inter_M(info_t *);
int itsDelim(char, char *);
int conAlpha(int);
int conv_in_str(char *);

/**err1.c */
int conINTtoSTR(char *);
void printError(info_t *, char *);
int printD(int, int);
char *convNum(long int, int, int);
void rmcomments(char *);

/** builtinside.c*/
int getOutt(info_t *);
int chTHacurrnetDIR(info_t *);
int chaningPID(info_t *);

/** builtinside1.c*/
int ourHIS(info_t *);
int myAalins(info_t *);

/** gLine.c */
ssize_t gInput(info_t *);
int gLine(info_t *, char **, size_t *);
void sToHandler(int);

/** gInfom.c */
void clsInfo(info_t *);
void sInfo(info_t *, char **);
void freeInform(info_t *, int);

/** enviro.c*/
char *getMyenv(info_t *, const char *);
int enveLinve(info_t *);
int aNewEnvv(info_t *);
int rmVarEnvv(info_t *);
int popEnvLl(info_t *);

/** gEnvo.c*/
char **gEnvo(info_t *);
int unSetEnvo(info_t *, char *);
int setEnvo(info_t *, char *, char *);

/** gHistory.c */
char *gHistoryFile(info_t *info);
int wrHistoryy(info_t *info);
int rHistory(info_t *info);
int bHistoryList(info_t *info, char *buf, int linecount);
int ren_History(info_t *info);

/** size_of_lists.c*/
list_t *addingNode(list_t **, const char *, int);
list_t *addingNode_end(list_t **, const char *, int);
size_t plstr(const list_t *);
int del_N(list_t **, unsigned int);
void frl(list_t **);

/** size_of_the_list.c*/
size_t lLn(const list_t *);
char **reStringss(list_t *);
size_t pl(const list_t *);
list_t *node_begins(list_t *, char *, char);
ssize_t getinX(list_t *, list_t *);

/** chain_del.c*/
int chain_del(info_t *, char *, size_t *);
void chCH(info_t *, char *, size_t *, size_t, size_t);
int replaceaLI(info_t *);
int reVars(info_t *);
int reString(char **, char *);

#endif

