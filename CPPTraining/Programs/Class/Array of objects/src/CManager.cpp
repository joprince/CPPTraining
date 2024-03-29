/**
 * File CEmpDetails.cpp - Copyright (C) <2019>
 * <Triassic Solutions Private Limited>. All rights reserved.
 * This file contains the member functions of  class "CManager".
 *
 *
 * Author   : Jewel Jo Prince
 * Version  : 1.0.0
 * Date     : 12-07-2019
 *
 */

#include "CManager.h"

// ------------------------------------------------------------------
// Method      : Intro
// Parameters  : Nil
// Returns     : Nil
// Description : Shows a basic introduction to program.
// ------------------------------------------------------------------
void CManager::Intro( void )
{
    cout<<"PROGRAM TO SORT EMPLOYEES BASED ON DESIGNATION\n";
    cout<<string(46,'_');
}

// ------------------------------------------------------------------
// Method      : AllocateSpace
// Parameters  : Nil
// Returns     : int
// Description : Allocate memory to array.
// ------------------------------------------------------------------
int CManager::AllocateSpace( void )
{
    cout<<"\n\nEnter the number of employees: ";
    cin>>m_nCount;
    getchar();

    if( CEmpDetails *pempDetails = new CEmpDetails[m_nCount] )
    {
        m_pEmpDetails = pempDetails;
        return 1;
    }
    else
    {
        return 0;
    }
}

// ------------------------------------------------------------------
// Method      : StoreData
// Parameters  :
//   <param 1> - <int nCount> - Current Array Count  from GetData().
// Returns     : int
// Description : Read employee details from user.
// ------------------------------------------------------------------
int CManager::StoreData( int nCount )
{
    cout<<"\n\nName: ";
    getline( cin,m_szName );
    cout<<"Available designations.";
    cout<<"\n\t1: Manager";
    cout<<"\n\t2: Developer";
    cout<<"\n\t3: Trainee";
    cout<<"\n\nEnter the number corresponding to the designation: ";
    cin>>m_nDesignation;
    cout<<"Age: ";
    cin>>m_nAge;
    cout<<"Salary: ";
    cin>>m_fSalary;
    getchar();
    return SortData( nCount );
}

// ------------------------------------------------------------------
// Method      : SortData
// Parameters  :
//   <param 1> - <int nCount> - Current array size.
// Returns     : int
// Description : Sorts and stores user data in array
// ------------------------------------------------------------------
int CManager::SortData( int nCount )
{
    int nTemp = 0;

    switch( m_nDesignation )
    {
        case 1: m_szDesignation = "Manager";
                DoShift( nCount,m_nTrainee + m_nDeveloper );
                nTemp = m_nManager++;
                break;

        case 2: m_szDesignation = "Developer";
                DoShift( nCount,m_nTrainee );
                nTemp = m_nManager + m_nDeveloper++;
                break;

        case 3: m_szDesignation = "Trainee";
                nTemp = m_nManager + m_nDeveloper + m_nTrainee++;
                break;

        default:return 0;
    }

    return m_pEmpDetails[nTemp].DataEntry( m_szName,m_szDesignation,m_nAge,m_fSalary );
}

// ------------------------------------------------------------------
// Method      : DoShift
// Parameters  :
//   <param 1> - <int nCount]> - Current array size.
//   <param 2> - <int nTemp> - Number of iteration needed.
// Returns     : void
// Description : Shifts array accordingly.
// ------------------------------------------------------------------
void CManager::DoShift( int nCount,int nIterate )
{
    while( nIterate > 0 )
    {
            m_pEmpDetails[nCount] = m_pEmpDetails[nCount-1];
            nIterate--;
            nCount--;
    }
}

// ------------------------------------------------------------------
// Method      : GetData
// Parameters  : void
// Returns     : void
// Description : Function that handles User Data Entry.
// ------------------------------------------------------------------
void CManager::GetData( void )
{
    int nTemp = 0;
    int nFlag = 1;

    system( "cls" );
    cout<<"\nEnter the details of "<<m_nCount<<" employees:\n";
    cout<<string(33,'_');
    while( nTemp < m_nCount )
    {
        nFlag = StoreData( nTemp );
        if( nFlag == 1)
        {
            cout<<"Data entry successful.";
            nTemp++;
        }
        else
        {
            cout<<"Invalid Input. Re-enter data.";
        }
    }
}

// ------------------------------------------------------------------
// Method      : PrintData
// Parameters  : void
// Returns     : void
// Description : Prints sorted user data to the screen.
// ------------------------------------------------------------------
void CManager::PrintData( void )
{
    int nTemp = 0;

    system( "cls" );
    cout<<"Details of employees grouped based on designation:\n";
    cout<<string(50,'_');
    cout<<"\n\nSI\tName\t\tAge\t\tSalary\t\tDesignation\n";
    while( nTemp < m_nCount )
    {
        cout<<"\n"<<nTemp+1;
        m_pEmpDetails[nTemp].DisplayData();
        nTemp++;
    }
    cout<<"\n\n\n\n";
}

// ------------------------------------------------------------------
// Method      : Destructor
// Parameters  : Nil
// Returns     : Nil
// Description : Deallocates the array memory.
// ------------------------------------------------------------------
CManager::~CManager( void )
{
    delete [] m_pEmpDetails;
}

// ------------------------------------------------------------------
// Method      : Constructor
// Parameters  : Nil
// Returns     : Nil
// Description : Initializes different variables.
// ------------------------------------------------------------------
CManager::CManager( void )
{
    m_pEmpDetails = NULL;
    m_nManager = 0;
    m_nDeveloper = 0;
    m_nTrainee = 0;
}

// ------------------------------------------------------------------
// Method      : ManageAll
// Parameters  : Nil
// Returns     : Nil
// Description : Manages all class functions.
// ------------------------------------------------------------------
void CManager::ManageAll( void )
{
    int nFlag = 0;

    Intro();
    nFlag = AllocateSpace();
    if( nFlag == 0 )
    {
        cout<<"Memory allocation failed. Press any key to exit.";
        getch();
        exit( 0 );
    }
    else
    {
        GetData();
        PrintData();
    }
}
