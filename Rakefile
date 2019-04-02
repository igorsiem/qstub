# Rakefile for basic Dev tasks in qStub
#
# Copyright Igor Siemienowicz 2018
# Distributed under the Boost Software License, Version 1.0. (See
# accompanying file LICENSE_1_0.txt or copy at
# https://www.boost.org/LICENSE_1_0.txt)

# --- Config ---

$project_name = "qstub"

# --- End Config ---

directory "build"

desc "clean all build artefacts"
task :clean do
    FileUtils.rm_rf "build"
end

desc "run conan to install / generate dependencies"
task :conan => "build" do
    Dir.chdir "build"
    sh "conan install ../src"
    Dir.chdir ".."
end

desc "run cmake to produce platform-specific build files"
task :cmake => :conan do
    Dir.chdir "build"

    cmake_cmd = "cmake "
    cmake_cmd += "-G \"Visual Studio 15 2017 Win64\" " \
        if Rake::Win32::windows?
    cmake_cmd += "../src"

    sh cmake_cmd

    Dir.chdir ".."
end

desc "build binaries"
task :bin => :cmake do    
    Dir.chdir "build"

    make_cmd = "make -j8"

    make_cmd =
            "msbuild /m #{$project_name}.sln " +
            "/p:Configuration=Release " +
            "/p:Platform=\"x64\" " +
            "" if Rake::Win32::windows?

    sh make_cmd

    Dir.chdir ".."
end

desc "run test suite"
task :test => :bin do
    sh "build/bin/test-#{$project_name}"
end

desc "run the application"
task :run => :bin do
    sh "build/bin/#{$project_name}-gui"
end

###directory "build/docs"
###
###desc "build doxygen docs"
###task :docs => "build/docs" do
###    sh "doxygen"
###end

###desc "build tests, run tests and build docs"
###task :all => [:bin, :test, :docs]
###
###task :default => :all
