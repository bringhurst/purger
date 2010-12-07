#ifndef PFILENODE_H
#define PFILENODE_H
/*******************************************************************************
  Copyright 2008-2010 Los Alamos National Security, LLC. All Rights Reserved.

  Redistribution and use in source and binary forms, with or without
  modification, are permitted provided that the following conditions are met:

     o Redistributions of source code must retain the above copyright notice,
       this list of conditions and the following disclaimer.
     o Redistributions in binary form must reproduce the above copyright
       notice, this list of conditions and the following disclaimer in the
       documentation and/or other materials provided with the distribution.
     o Neither the name of the copyright holders nor the names of its
       contributors may be used to endorse or promote products derived from
       this software without specific prior written permission.

  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
  AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
  IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
  ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
  LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
  CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
  SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
  INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
  CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
  ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
  POSSIBILITY OF SUCH DAMAGE.
*******************************************************************************/

/**
 * \file pfilenode.h
 * \author Jharrod LaFon
 * \date Summer 2010
 * \brief A class to represent items in a PFileSystemModel.
 */

#include <QList>
#include <QVariant>

class pFileNode
{
public:
    enum Roles { FileIconRole, FilePathRole, FileNameRole, FilePermissions };
    pFileNode(const QList<QVariant> &data, pFileNode *parent = 0);
    ~pFileNode();
    void removeChildren();
    void appendChild(pFileNode *child);
    pFileNode * child(int row);
    int childCount() const;
    int columnCount() const;
    QVariant data(int column) const;
    void addData(QList<QVariant> &data);
    void setData(QList<QVariant> &data);
    bool hasChildren() const;
    int row() const;
    pFileNode *parent();

private:
    void setDir() { this->isDir = true; }
    bool isDir;
    QList<pFileNode*> childItems;
    QList<QVariant> itemData;
    pFileNode *parentItem;
};

#endif // PFILENODE_H
