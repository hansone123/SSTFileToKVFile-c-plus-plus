/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Job.h
 * Author: hansone123
 *
 * Created on April 25, 2016, 9:36 PM
 */

#ifndef JOB_H
#define JOB_H

class Job {
public:
    Job();
    Job(const Job& orig);
    virtual void execute()=0;
    virtual ~Job();
private:

};

#endif /* JOB_H */

