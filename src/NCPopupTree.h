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

   File:       NCPopupTree.h

   Author:     Gabriele Strattner <gs@suse.de>
   Maintainer: Michael Andres <ma@suse.de>

/-*/
#ifndef NCPopupTree_h
#define NCPopupTree_h

#include <iosfwd>

#include <vector>
#include <string>

#include "NCPopup.h"
#include "NCTree.h"
#include "NCLabel.h"
#include "NCRichText.h"
#include "YPkgRpmGroupTagsFilterView.h"

class NCTree;
class YCPValue;

///////////////////////////////////////////////////////////////////
//
//	CLASS NAME : NCPopupTree
//
//	DESCRIPTION :
//
class NCPopupTree : public NCPopup {

    NCPopupTree & operator=( const NCPopupTree & );
    NCPopupTree            ( const NCPopupTree & );

private:

    NCTree * filterTree;
    NCRichText * description;
    YPkgRpmGroupTagsFilterView * groups; // the RPM groups    

    // internal use (copies tree items got from YPkgRpmGroupTagsFilterView)
    void cloneTree( YPkgStringTreeItem * parentOrig, YTreeItem * parentClone );

protected:

    void setCurrentItem( int index );
    string getCurrentItem() const;

    virtual NCursesEvent wHandleHotkey( int ch );

    virtual bool postAgain();

    virtual NCursesEvent wHandleInput( int ch );
    
public:
    
    NCPopupTree( const wpos at, bool hasDescr );
    virtual ~NCPopupTree();

    virtual long nicesize(YUIDimension dim);

    void createLayout( const YCPString & label, bool hasDescr );

    YTreeItem * addItem( YTreeItem * 		parentItem,
			 const YCPString & 	text,
			 void * 		data,
			 bool  			open );

    NCursesEvent showFilterPopup( );
    
};

///////////////////////////////////////////////////////////////////


#endif // NCPopupTree_h