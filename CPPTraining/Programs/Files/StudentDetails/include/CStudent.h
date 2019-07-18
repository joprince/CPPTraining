/**
 * File CSudent.h - Copyright (C) <2019>
 * <Triassic Solutions Private Limited>. All rights reserved.
 * This file contains the declaration of a Class "CStudent"
 * to handle student details
 *
 * Author   : Jewel Jo Prince
 * Version  : 1.0.0
 * Date     : 18-07-2019
 *
 */


#ifndef CSTUDENT_H
#define CSTUDENT_H

#include <iostream>
#include <ctime>

using namespace std;


/*
 * Class <CStudent>
 * <A class which stores details of students.>
 * Author : Jewel Jo Prince
 * Version : 2.0.0
 * Date : 12-07-2019
 *
 */
class CStudent
{
    private:
        int m_nAdmNo;
        string m_szName;
        char m_cGender;
        string m_szCourse;
        string m_szDateOfJoin;
    public:
        CStudent( void );
        void AddData( int, string, char, int, string );
        int GetAdmNo( void );
        void View( void );
        void ViewTab( void );
};

#endif // CSTUDENT_H