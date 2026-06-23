#include "Course.hpp"


Course::Course() {
    courseId = "";
    prerequisites = std::vector<std::string>(0);
}


Course::Course(std::string courseId, std::string title) {
    this->courseId = courseId;
    this->title = title; 
}


Course::Course(
    std::string courseId, 
    std::string title, 
    std::vector<std::string> prerequisites) 
{
    this->courseId = courseId;
    this->title = title; 
    this->prerequisites = prerequisites;
}


void Course::addPrerequisite(std::string prerequisite) {
    prerequisites.push_back(prerequisite);
}


std::string Course::getCourseId() {
    return courseId;
}

std::string Course::getTitle() {
    return title;
}

std::vector<std::string>* Course::getPrerequisites() {
    return &prerequisites;
}

bool Course::isValid() {
    return courseId != "" && title != "";
}

