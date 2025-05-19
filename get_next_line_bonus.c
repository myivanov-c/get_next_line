/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykytaivanov <mykytaivanov@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 23:08:32 by mykytaivano       #+#    #+#             */
/*   Updated: 2025/05/18 19:38:22 by mykytaivano      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#define FD_MAX 1024

static char     *read_and_append_bonus(int fd, char *stash)
{
    char    *buf;
    ssize_t bytes;

    buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
    if (!buf)
        return (free(stash), (NULL));
    bytes = 1;
    while (bytes > 0 && !ft_strchr_gnl_bonus(stash, '\n'))
    {
        bytes = read(fd, buf, BUFFER_SIZE);
        if (bytes == -1)
            return (free(buf), free(stash), (NULL));
        buf[bytes] = '\0';
        stash = ft_strjoin_gnl_bonus(stash, buf);
        if (!stash)
            return (free(buf), (NULL)); 
    }
    free (buf);
    return (stash);
}

static char     *extract_line_bonus(char *stash)
{
    size_t  i;
    
    if (!stash[0])
        return (NULL);
    i = 0;
    while (stash[i] != '\0' && stash[i] != '\n')
        i++;
    if (stash[i] == '\n')
        i++;
    return (ft_substr_gnl_bonus(stash, 0, i));
}

static char     *clean_stash_bonus(char *stash)
{
    char    *new_stash;
    size_t  i;

    i = 0;
    while (stash[i] != '\0' && stash[i] != '\n')
        i++;
    if (!stash[i])
        return (free(stash), (NULL));
    i++;
    new_stash = ft_strdup_gnl_bonus(&stash[i]);
    free (stash);
    return (new_stash);
}
static char     *free_and_nullify(char **ptr)
{
    free(*ptr);
    *ptr = NULL;
    return (NULL);
}

char    *get_next_line_bonus(int fd)
{
    static char     *stash[FD_MAX];
    char            *line;

    if (fd < 0 || fd >= FD_MAX || BUFFER_SIZE <= 0)
        return (NULL);
    if (!stash[fd])
    {
        stash[fd] = ft_strdup_gnl_bonus("");
        if (!stash[fd])
            return (NULL);
    }        
    stash[fd] = read_and_append_bonus(fd, stash[fd]);
    if (!stash[fd])
        return (NULL);
    if (!stash[fd][0])
        return (free_and_nullify(&stash[fd]));
    line = extract_line_bonus(stash[fd]);
    if (!line)
        return (free_and_nullify(&stash[fd]));
    stash[fd] = clean_stash_bonus(stash[fd]);
    return (line);
}
/*int     main(void)
{
    int     fd1;
    int     fd2;
    int     fd3;
    int     end1;
    int     end2;
    int     end3;
    int     i;
    char    *line1;
    char    *line2;
    char    *line3;

    fd1 = open("get_next_line_bonus.h", O_RDONLY);
    fd2 = open ("get_next_line_bonus.c", O_RDONLY);
    fd3 = open ("get_next_line_utils_bonus.c", O_RDONLY);
    if (fd1 < 0 || fd2 < 0 || fd3 < 0)
    {
        perror ("Error ao abrir ficheiro.\n");
        return (1);
    }
    i = 0;
    end1 = 0;
    end2 = 0;
    end3 = 0;
    while (!end1 || !end2 || !end3)
    {
        if (!end1)
        {
            line1 = get_next_line_bonus(fd1);
            if (line1)
            {
                printf("FD1 [%d]: %s",  i,  line1);
                if (line1[0] == '\0' || line1[ft_strlen_gnl_bonus(line1) - 1] != '\n')
                    printf("\n");
                free (line1);
            }
             else
                    end1 = 1;
        }
        if (!end2)
        {
            line2 = get_next_line_bonus(fd2);
            if (line2)
            {
                printf("FD2 [%d]: %s", i, line2);
                if (line2[0] == '\0' || line2[ft_strlen_gnl_bonus(line2) - 1] != '\n')
                    printf("\n");
                free(line2);
            }
             else
                    end2 = 1;
        }
        if (!end3)
        {
            line3 = get_next_line_bonus(fd3);
            if (line3)
            {
                printf("FD3 [%d]: %s", i, line3);
                if (line3[0] == '\0' || line2[ft_strlen_gnl_bonus(line3) - 1] != '\n')
                    printf("\n");
                free (line3);
            }
             else
                    end3 = 1;
        }
        i++;
    }
    close (fd1);
    close (fd2);
    close (fd3);
    return (0);
}*/