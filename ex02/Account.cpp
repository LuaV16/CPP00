/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvargas- <lvargas-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 17:54:03 by lvargas-          #+#    #+#             */
/*   Updated: 2026/02/01 20:16:59 by lvargas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <ctime>
#include <sstream>
#include <iostream>

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

void	Account::_displayTimestamp(void)
{
    std::time_t timeStamp = std::time(NULL);
    std::tm *tm = localtime(&timeStamp);
    char buffer[19];
    
    std::strftime(buffer, sizeof(buffer), "[%Y%m%d_%H%M%S] ", tm);
    std::cout << buffer;
}

Account::Account(int initial_deposit):_accountIndex(_nbAccounts), _amount(initial_deposit), _nbDeposits(0), _nbWithdrawals(0)
{
    _nbAccounts++;
    _totalAmount += initial_deposit;
    _displayTimestamp();
    std::cout << "index:" << _accountIndex
              << ";amount:" << _amount
              << ";created" << std::endl;
}

Account::~Account( void )
{
    _displayTimestamp();
    std::cout << "index:" << _accountIndex
              << ";amount:" << _amount
              << ";closed" << std::endl;
}

int Account::getNbAccounts( void )
{
    return(_nbAccounts);
}

int	Account::getTotalAmount( void )
{
    return(_totalAmount);
}
int	Account::getNbDeposits( void )
{
    return (_totalNbDeposits);
}
int	Account::getNbWithdrawals( void )
{
    return (_totalNbWithdrawals);
}
void	Account::displayAccountsInfos( void )
{
    _displayTimestamp();
    std::cout << "accounts:" << _nbAccounts 
              << ";total:"   << _totalAmount 
              << ";deposits:" << _totalNbDeposits
              << ";withdrawals:" << _totalNbWithdrawals
              << std::endl;
}

void	Account::makeDeposit( int deposit )
{
    int p_amount = _amount;
    _amount += deposit;
    _nbDeposits += 1;
    _totalAmount += deposit;
    _totalNbDeposits += 1;

    _displayTimestamp();
    std::cout << "index:"        << _accountIndex
              << ";p_amount:"    << p_amount
              << ";deposit:"     << deposit
              << ";amount:"      << _amount
              << ";nb_deposits:" << _nbDeposits
              << std::endl;
}

bool	Account::makeWithdrawal( int withdrawal )
{
    if (withdrawal > _amount)
    {
        _displayTimestamp();
        std::cout << "index:" << _accountIndex
                  << ";p_amount:" << _amount
                  << ";withdrawal:refused"
                  << std::endl;
        return (false);
    }
    int p_amount = _amount;
    _amount = _amount - withdrawal;
    _nbWithdrawals += 1;
    _totalAmount = _totalAmount - withdrawal;

    _displayTimestamp();
    std::cout << "index:"           << _accountIndex
              << ";p_amount:"       << p_amount
              << ";withdrawal:"     << withdrawal
              << ";amount:"         << _amount
              << ";nb_withdrawals:" << _nbWithdrawals
              << std::endl;
    return (true);
}

int		Account::checkAmount( void ) const
{
    return (_amount);
}

void	Account::displayStatus( void ) const
{
    _displayTimestamp();
    std::cout << "index:" << _accountIndex
              << ";amount:" << _amount
              << ";deposits:" << _nbDeposits
              << ";withdrawals:" << _nbWithdrawals
              << std::endl;
}

