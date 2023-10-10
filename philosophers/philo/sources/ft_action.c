#include "../include/philosophers.h"

void ft_die(t_philo *philo, int i)
{
    pthread_mutex_lock(philo->dead_lock);
    *(philo[i].dead) = TRUE;
    pthread_mutex_unlock(philo->dead_lock);
    //ft_print_action("died\n", philo, i);
}

void ft_eat(t_philo *philo, int i)
{
    // if ((get_proper_time() - philo[i].last_meal_time) >= philo->time_to_die)
    //     ft_die(philo, i);
    pthread_mutex_lock(&philo[i].right_fork);
    ft_print_action("has taken the right fork\n", philo, i);
    pthread_mutex_lock(&philo[i].left_fork);
    ft_print_action("has taken the left fork\n", philo, i);
    pthread_mutex_lock(philo[i].food_lock);
    (*philo[i].meals_total)++;
    philo[i].last_meal_time = get_proper_time();
    pthread_mutex_unlock(philo[i].food_lock);
    //on incremente le nombre de repas mange
    ft_print_action("is eating\n", philo, i);
    // ft_usleep(philo[i].time_to_sleep);
    usleep(10000);
    pthread_mutex_unlock(&philo[i].right_fork);
    pthread_mutex_unlock(&philo[i].right_fork);
    return;
}

void ft_sleep(t_philo *philo, int i)
{
    ft_print_action("is sleeping\n", philo, i);
    //pthread_mutex_lock(philo[i].sleep_lock);
    ft_usleep(philo[i].time_to_sleep);
    //pthread_mutex_unlock(philo[i].sleep_lock);
    return;
}

void ft_think(t_philo *philo, int i)
{
    //pthread_mutex_lock(&philo[i].lock);
    ft_print_action("is thinking\n", philo, i);
    //pthread_mutex_unlock(&philo[i].lock);    
    return;
}
