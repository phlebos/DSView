/*
 * This file is part of the PulseView project.
 *
 * Copyright (C) 2013 Joel Holdsworth <joel@airwebreathe.org.uk>
 * Copyright (C) 2014 DreamSourceLab <support@dreamsourcelab.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301 USA
 */

#include "AnnotationResTable.h"
#include <assert.h>
 

AnnotationResTable::AnnotationResTable(){
    
}

AnnotationResTable::~AnnotationResTable(){
     
}

int AnnotationResTable::MakeIndex(const std::string &key, AnnotationStringList *&ls)
{   
    auto fd =m_indexs.find(key);
    if (fd != m_indexs.end()){
        return (*fd).second;
    } 
 
    int dex = m_indexs.size();
    m_indexs[key] = dex;

    //make a new string vector
    m_resourceTable.push_back(AnnotationStringList());
    ls = &m_resourceTable[dex];
   
    return dex;
}

const AnnotationStringList& AnnotationResTable::GetString(int index){
    int num = m_resourceTable.size();
    assert(index >= 0 && index < num);
    return m_resourceTable[index];
}
 
