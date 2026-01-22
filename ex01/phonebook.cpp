/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvargas- <lvargas-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 12:12:25 by lvargas-          #+#    #+#             */
/*   Updated: 2026/01/22 13:09:29 by lvargas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"
#include "contact.hpp"

static int parse_input(const std::string &input)
{
    std::istringstream str(input);
    std::string token;
    std::string extra;

    if (!(str >> token))
        return (1);
    if (str >> extra)
        return (1);
    if (token == "ADD")
        return (2);
    else if (token == "SEARCH")
        return (3);
    else if (token == "EXIT")
        return (4);
    else
        return (1);
    
    return (1);
}

int main(void)
{
    std::string input;
    
    while (true)
    {
        std::cout << "ADD, SEARCH or EXIT" << std::endl;
        std::getline(std::cin, input);
        if (parse_input(input))
        {
            
        }
    }
    return (0);
}
