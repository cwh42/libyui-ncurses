/*---------------------------------------------------------------------\
|                                                                      |
|                      __   __    ____ _____ ____                      |
|                      \ \ / /_ _/ ___|_   _|___ \                     |
|                       \ V / _` \___ \ | |   __) |                    |
|                        | | (_| |___) || |  / __/                     |
|                        |_|\__,_|____/ |_| |_____|                    |
|                                                                      |
|                               core system                            |
|                                                        (C) SuSE GmbH |
\----------------------------------------------------------------------/

   File:       NCPopupSelDeps.cc

   Author:     Gabriele Strattner <gs@suse.de>
   Maintainer: Michael Andres <ma@suse.de>

/-*/
#include "Y2Log.h"
#include "NCPopupSelDeps.h"

#include "NCTree.h"
#include "YMenuButton.h"
#include "YDialog.h"
#include "NCSplit.h"
#include "NCSpacing.h"
#include "PkgNames.h"
#include "NCPkgTable.h"
#include "NCMenuButton.h"
#include "NCPushButton.h"
#include "NCPopupInfo.h"
#include "ObjectStatStrategy.h"

#include <y2pm/PMSelectionManager.h>

using namespace std;

///////////////////////////////////////////////////////////////////
//
//
//	METHOD NAME : NCPopupSelDeps::NCPopupSelDeps
//	METHOD TYPE : Constructor
//
//	DESCRIPTION :
//
NCPopupSelDeps::NCPopupSelDeps( const wpos at, PackageSelector * pkger )
    : NCPopupDeps( at, pkger )
{

}

///////////////////////////////////////////////////////////////////
//
//
//	METHOD NAME : NCPopupSelDeps::~NCPopupSelDeps
//	METHOD TYPE : Destructor
//
//	DESCRIPTION :
//
NCPopupSelDeps::~NCPopupSelDeps()
{

}

///////////////////////////////////////////////////////////////////
//
//
//	METHOD NAME : NCPopupSelDeps::solveInstall
//	METHOD TYPE : bool
//
//	DESCRIPTION :
//
bool NCPopupSelDeps::solveInstall( PkgDep::ResultList & goodList, PkgDep::ErrorResultList & badList )
{
    return Y2PM::selectionManager().solveInstall( goodList, badList );
}

