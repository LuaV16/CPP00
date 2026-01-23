/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvargas- <lvargas-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 13:34:08 by lvargas-          #+#    #+#             */
/*   Updated: 2026/01/23 18:00:51 by lvargas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "Phonebook.hpp"

std::string Contact::getFirstName() const
{
    return firstName;
}

std::string Contact::getLastName() const
{
    return lastName;
}

std::string Contact::getNickName() const
{
    return nickName;
}

std::string Contact::getPhoneNumber() const
{
    return phoneNumber;
}

std::string Contact::getDarkestSecret() const
{
    return darkestSecret;
}

void Contact::setFirstName(const std::string &str)
{
    firstName = str;
}

void Contact::setLastName(const std::string &str)
{
    lastName = str;
}

void Contact::setNickName(const std::string &str)
{
    nickName = str;
}

void Contact::setPhoneNumber(const std::string &str)
{
    phoneNumber = str;
}

void Contact::setDarkestSecret(const std::string &str)
{
    darkestSecret = str;
}
