module.exports = function(grunt) {
  grunt.initConfig({
    pkg: grunt.file.readJSON('package.json'),
    watch: {
      sass: {
        files: ['sass/*.{scss,sass}','scss/**/*.{scss,sass}','sass/**/*.{scss,sass}'],
        tasks: ['sass:dist']
      },
      livereload: {
        files: ['*.html', '*.php', 'js/**/*.{js,json}', 'css/*.css','images/**/*.{png,jpg,jpeg,gif,webp,svg}'],
        options: {
          livereload: true
        }
      }
    },
    sass: {
      dist: {
        files: {
          'css/style.css': 'sass/style.scss',
          'css/mr.css': 'sass/mr.scss',
          'css/mr.reset.css': 'sass/mr.reset.scss',
          'css/layout.css': 'sass/layout.scss',
        }
      }
    },
    imagemin: {
      dynamic: {
        files: [{
          expand: true,
          cwd: 'assets/images',
          src: ['**/*.{png,jpg,gif}'],
          dest: 'images'
        }]
      }
    }
  });
  grunt.registerTask('default', ['sass:dist', 'imagemin', 'watch']);
  grunt.loadNpmTasks('grunt-contrib-sass');
  grunt.loadNpmTasks('grunt-contrib-coffee');
  grunt.loadNpmTasks('grunt-contrib-imagemin');
  grunt.loadNpmTasks('grunt-contrib-watch');
};