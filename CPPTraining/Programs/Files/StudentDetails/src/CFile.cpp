#include "CFile.h"

CFile::CFile( void )
{
    istorage.open( "STUDENT.dat", ios::in | ios::binary );
    if( !istorage )
    {
        cout<<"File access failed or file does not exist."<<endl;
        exit( 0 );
    }
    else
    {
        //unimplemented
    }
    ostorage.open("STUDENT.dat", ios::out| ios::in | ios::binary | ios::ate );
    if( !ostorage )
    {
        cout<<"File access failed or file does not exist."<<endl;
        exit( 0 );
    }
    else
    {
        //unimplemented
    }
}
void CFile::Write( CStudent data )
{
    ostorage.write( ( char* )( &data ),sizeof( data ) );
    ostorage.flush();
}

CStudent CFile::GetData( int nAdmNo )
{
  CStudent temp;
/*
    istorage.open( "STUDENT.dat", ios::in | ios::binary );
    if( !istorage )
    {
        cout<<"File access failed or file does not exist."<<endl;
        exit( 0 );
    }
    else
    {
        //unimplemented
    }
    istorage.seekg( 0, ios::beg );
    while( !istorage.eof() )
    {
        istorage.read( ( char* )&temp,sizeof( temp ) );
        if( nAdmNo == temp.GetAdmNo() )
        {
            return temp;
        }
        else
        {
            //unimplemented
        }
    }
    istorage.close();
    */
    return temp;
}

void CFile::ViewAll( void )
{
    CStudent temp;
    cout<<istorage.tellg()<<"\n";
    istorage.seekg( 0, ios::beg );
    cout<<istorage.tellg()<<"\n"<<istorage.eof();
    while( istorage.read( ( char* )&temp, sizeof( CStudent ) ) )
    {
        temp.ViewTab();
        cout<<endl;

    }
    cout<<istorage.tellg();
}

void CFile::ClearSpec( int nAdmNo )
{/*
    CStudent temp;
    ofstream fout("temp.dat", ios::out | ios::binary | ios::trunc );
    while( istorage.read( ( char* )&temp, sizeof( temp ) ) )
    {
        if( temp.GetAdmNo() != nAdmNo )
        {
            fout.write( ( char* )&temp,sizeof( temp ) );
        }
        else
        {
            //else unimplemented
        }
    }*/
}

void CFile::ClearFile( void )
{
    istorage.close();
    ostorage.close();
    remove( "STUDENT.dat" );
    ostorage.open("STUDENT.dat", ios::out | ios::binary );
    if( !ostorage )
    {
        cout<<"File access failed or file does not exist."<<endl;
        exit( 0 );
    }
    else
    {
        //unimplemented
    }
    ostorage.close();
}

CFile::~CFile( void )
{
    ostorage.close();
    istorage.close();
}
