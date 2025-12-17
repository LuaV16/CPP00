/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvargas- <lvargas-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 15:32:41 by lvargas-          #+#    #+#             */
/*   Updated: 2025/12/17 16:00:15 by lvargas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cctype>
#include <iostream>
#include <string>

int main(int argc, char *argv[])
{    
    if (argc == 1)
    {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
        return (0);
    }
    
    for (int n = 1; n <= argc; n++)
    {
        std::string str = argv[n];
        for (std::size_t i = 0; i < str.length(); i++)
            str[i] = 
    }
    std::cout << std::endl;
    return (0);
}