#include "../include/philosophers.h"
// void    ft_destroy_threads(t_philo  *philo)
// {
//     int i;

//     i = 0;
//     pthread_mutex_destroy(philo->dead_lock);
//     pthread_mutex_destroy(philo->sleep_lock);
//     pthread_mutex_destroy(philo->food_lock);
//     pthread_mutex_destroy(philo->print_lock);
//     while (i < philo.amount)
//     {
//         pthread_mutex_destroy(&philo[i].left_fork);
//         pthread_mutex_destroy(&philo[i].right_fork);
//         i++;
//     }
// }

int    ft_check_all_eat(t_philo *philo)
{
    int end;

    end = philo->total_eating_round * philo[0].amount;

    if (*(philo->meals_total) >= end)
    {
        *(philo->dead) = TRUE;
        return(1);
    }
    return(0);
}

int   ft_check_death(t_philo *philo)
{
    int i;

    i = 0;
    while(i < philo[0].amount)
    {
        pthread_mutex_lock(philo[0].dead_lock);
        if(get_proper_time() - philo->last_meal_time >= philo[0].time_to_die)
            return(1);
        pthread_mutex_lock(philo[0].dead_lock);
        i++;
    }
    return(0);
}

void    *ft_checker(void *param)
{
    t_philo *philo;
    int     i;

    i = 0;
    philo = param;
    //ici on va checker les statuts des philos si il y en a qui sont morts
    //if the philo.dead = TRUE or philo.full = TRUE -> on va arreter le programme
    while(1)
    {
        if(ft_check_death(philo) || ft_check_all_eat(philo))
        {
            //ft_destroy_threads(philo);
            break;
        }
    }
    //ft_check_all_eat(philo);
    return(philo);
}