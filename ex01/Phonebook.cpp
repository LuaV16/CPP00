/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvargas- <lvargas-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 12:12:25 by lvargas-          #+#    #+#             */
/*   Updated: 2026/01/26 18:04:47 by lvargas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"
#include "Contact.hpp"

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

std::string truncate(std::string str)
{
    if (str.size() <= 10)
        return (str);
    return (str.substr(0, 9) + '.');
}

void display_phonebook(Phonebook &pb, int total)
{
    if (total == 0)
    {
        std::cout << "THE PHONEBOOK IS EMPTY." << std::endl;
        return ;
    }
    std::cout << std::left 
              << std::setw(10) << "INDEX" << "|"
              << std::setw(10) << "FIRST NAME" << "|"
              << std::setw(10) << "LAST NAME" << "|"
              << std::setw(10) << "NICKNAME"
              << std::endl;
    
    for (int n = 0; n < total; n++)
    {
        std::cout << std::left 
              << std::setw(10) << n << "|"
              << std::setw(10) << truncate(pb.contact[n].getFirstName()) << "|"
              << std::setw(10) << truncate(pb.contact[n].getLastName()) << "|"
              << std::setw(10) << truncate(pb.contact[n].getNickName())
              << std::endl;
    }
}

void display_contact(Phonebook pb, int total)
{
    std::string input;
    std::string extra;
    int index;
    
    while (1)
    {
        std::cout << "INSERT INDEX:" << std::endl;
        if (!std::getline(std::cin, input))
            return ;
        std::istringstream iss(input);
        if (!(iss >> index) || (iss >> extra) || index >= total || index < 0)
        {
            std::cout << "INVALID INDEX. TRY AGAIN." << extra << std::endl;
            continue ;
        }
        else
        {
            std::cout << "FIRST NAME: " << pb.contact[index].getFirstName() << std::endl;
            std::cout << "LAST NAME: " << pb.contact[index].getLastName() << std::endl;
            std::cout << "NICKNAME: " << pb.contact[index].getNickName() << std::endl;
            std::cout << "PHONE NUMBER: " << pb.contact[index].getPhoneNumber() << std::endl;
            std::cout << "DARKEST SECRET: " << pb.contact[index].getDarkestSecret() << std::endl;
            return ;
        }
    }
}

void add_contact(Phonebook &pb, int next_index)
{
    std::string questions[5];
    std::string input[5];

    questions[0] = "FIRST NAME:";
    questions[1] = "LAST NAME:";
    questions[2] = "NICKNAME:";
    questions[3] = "PHONE NUMBER:";
    questions[4] = "DARKEST SECRET:";
    
    for (int n = 0; n < 5; n++)
    {
        std::cout << questions[n] << std::endl;
        if (!std::getline(std::cin, input[n]))
            return ;
        if (input[n].empty())
        {
            std::cout << "Field cannot be empty." << std::endl;
            n--;
            continue;
        }
    }

    int n = 0;
    pb.contact[next_index].setFirstName(input[n++]);
    pb.contact[next_index].setLastName(input[n++]);
    pb.contact[next_index].setNickName(input[n++]);
    pb.contact[next_index].setPhoneNumber(input[n++]);
    pb.contact[next_index].setDarkestSecret(input[n++]);
    
    std::cout << "CONTACT ADDED SUCCESSFULLY." << std::endl << std::endl;
}

int main(void)
{
    std::string input;
    int option;
    int next_index = 0;
    int total = 0;
    Phonebook pb;
    
    while (true)
    {
        std::cout << "ADD, SEARCH or EXIT" << std::endl;
        if (!std::getline(std::cin, input))
            break ;
        option = parse_input(input);
        if (option == 2)
        {
            add_contact(pb, next_index);
            if (next_index == 7)
                next_index = 0;
            else
                next_index += 1;
            if (total < 8)
                total++;
        }
        else if (option == 3)
        {
            display_phonebook(pb, total);
            if (total != 0)
                display_contact(pb, total);
        }
        else if (option == 4)
            break;
    }
    return (0);
}
