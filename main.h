#ifndef MAIN_H_
#define MAIN_H_
void shell_loop(void);
char shell_read_line(void);
char **shell_split_line(char *line);
int shell_launch(char **args);
int shell_execute(char **args);
int (*builtin_fun[])(char **);
int shell_num_builtins();
char *builtin_str[];
int shell_cd(char **args);
int shell_help(char **args);
int shell_exit(char **args);
#endif
